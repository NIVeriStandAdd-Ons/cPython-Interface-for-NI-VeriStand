using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using NationalInstruments.Tdms;
using System.Runtime.CompilerServices;
using System.Text.RegularExpressions;

[assembly: InternalsVisibleTo("VeristandPythonInteropTest")]
namespace VeristandPythonInterop
{
    public class VeriStandTDMSHandler
    {
        internal TdmsFile logFile { get; set; }
        internal string logGroup { get; set; }
        internal TdmsProperty loggingRate { get; set; }
        internal TdmsChannelCollection channelsFETCH { get; set; }
        internal TdmsChannelGroupCollection channelGroupsFETCH { get; set; }
        int logChannelCount;
        long logLength;

        public void TDMSOpen(string filePath)
        {
            logFile = new TdmsFile(filePath, new TdmsFileOptions(TdmsFileFormat.Version20, TdmsFileAccess.Read));
            logGroup = "EXAM_Data";

            // Get the channel group
            this.channelGroupsFETCH = logFile.GetChannelGroups();
            if (!this.channelGroupsFETCH.Contains(logGroup)) throw new SystemException("Group not found in tdms file!");
            TdmsChannelGroup channelGroupFETCH = this.channelGroupsFETCH[logGroup];

            // Get the channels        
            channelsFETCH = channelGroupFETCH.GetChannels();
            logChannelCount = channelsFETCH.Count;
            logLength = channelsFETCH[0].DataCount;
            
            loggingRate = logFile.GetProperty("EXAM_LoggingRate");                        
        }

        public void TDMSClose()
        {
            logFile.Close();
        }

        public double GetTDMSLoggingRate()
        {
            string sRate = loggingRate.GetValue<String>();
            string sRateParsed = Regex.Match(sRate, @"\d+").Value;
            return Double.Parse(sRateParsed);
            //return loggingRate.GetValue<Double>();            
        }

        public int GetTDMSLogChannelCount()
        {
            return logChannelCount;
        }

        public long GetTDMSLogLength()
        {
            return logLength;
        }

        public string GetTDMSLogChannelProperty(int channelIndex, string propertyName)
        {
            TdmsProperty retTDMSproperty;
            TdmsChannel tempChannel = channelsFETCH[channelIndex];

            retTDMSproperty = tempChannel.GetProperty(propertyName);
            
         //"ChannelShortName"
            return retTDMSproperty.GetValue<String>(); ;
        }

        public double[] TDMSReadLine(int reqLine)
        {
            double[] logLine = new double[logChannelCount];            
            for (int i = 0; i < logChannelCount; i++)
            {
                TdmsChannel tempChannel = channelsFETCH[i];
                logLine[i] = tempChannel.GetData<double>(reqLine, 1)[0];
            }

            return logLine;
        }

        public double[] TDMSReadColumn(int reqColumn)
        {
            double[] logColumn = new double[logLength];
            TdmsChannel tempChannel = channelsFETCH[reqColumn];
            logColumn = tempChannel.GetData<double>(0, (int) logLength);

            return logColumn;
        }

        public double[] TDMSTimeColumn()
        {
            double[] logColumn = new double[logLength];

            TdmsChannelGroup channelGroupFETCHTime = this.channelGroupsFETCH["EXAM_Data_Internal"];

            // Get the channels        
            TdmsChannelCollection channelsFETCHTime = channelGroupFETCHTime.GetChannels();            
            TdmsChannel tempChannel = channelsFETCHTime["System Time"];
            logColumn = tempChannel.GetData<double>(0, (int) logLength);

            return logColumn;
        }
    }
}