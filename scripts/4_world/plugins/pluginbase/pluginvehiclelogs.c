class PluginVehicleLogs extends PluginBase
{
	bool			m_LogEnabled	= false;
	FileHandle		m_LogFile;
	string			m_archives		= "$profile:/LogArchives";
	
	// Time variables for use in timestamping cycled files and inside logs
	int year, month, day, hour, minute, second;
	string sYear, sMonth, sDay, sHour, sMinute, sSecond, currentTime;
	
	void PluginVehicleLogs()
	{
		Print("Init: PluginVehicleLogs");
		
		if (!FileExist(m_archives))
			MakeDirectory(m_archives);
		
		if (!FileExist(m_archives + "/VehicleActivity"))
			MakeDirectory(m_archives + "/VehicleActivity");

		if (FileExist("$profile:/VehicleActivity.log"))
		{
			// Setting Time Variables for new file name
			GetYearMonthDay(year, month, day);
			GetHourMinuteSecond(hour, minute, second);
			
			// Setting String for Time Variables for new file name
			sYear = year.ToString();
			
			sMonth = month.ToString();
			if (sMonth.Length() == 1)
			{
				sMonth = "0" + sMonth;
			}
			
			sDay = day.ToString();
			if (sDay.Length() == 1)
			{
				sDay = "0" + sDay;
			}
			
			sHour = hour.ToString();
			if (sHour.Length() == 1)
			{
				sHour = "0" + sHour;
			}
			
			sMinute = minute.ToString();
			if (sMinute.Length() == 1)
			{
				sMinute = "0" + sMinute;
			}
			
			sSecond = second.ToString();
			if (sSecond.Length() == 1)
			{
				sSecond = "0" + sSecond;
			}
			
			currentTime = "_" + sYear + "-" + sMonth + "-" + sDay + "_" + sHour + "-" + sMinute + "-" + sSecond;
			
			// Setting String for new file name
			string newFileName = m_archives + "/VehicleActivity/VehicleActivity" + currentTime + ".log";
			
			// Copying Old Log to New Log filename
			CopyFile("$profile:/VehicleActivity.log", newFileName);
			
			// Removing Old Log to ensure no issues.
			DeleteFile("$profile:/VehicleActivity.log");
			
			// Create New Log
			if (this.CreateNewLogFile())
			{
				m_LogEnabled = true;
				return;
			}
		}
		else
		{
			// Create New Log
			if (this.CreateNewLogFile())
			{
				m_LogEnabled = true;
				return;
			}
		}
	}
	
	void ~PluginVehicleLogs()
	{
		Print("~PluginVehicleActivityLogs Closed");
		if (GetGame().IsServer())
		{
			// Close Log File
			CloseFile(m_LogFile);
		}
	}
	
	bool CreateNewLogFile()
	{
		if (GetGame().IsServer())
		{
			m_LogFile = OpenFile("$profile:/VehicleActivity.log", FileMode.WRITE);
			if (m_LogFile != 0)
			{
				// Getting Current Time and Date
				GetYearMonthDay(year, month, day);
				GetHourMinuteSecond(hour, minute, second);
				
				// Setting String for Time Variables for new file name
				sYear = year.ToString();
				
				sMonth = month.ToString();
				if (sMonth.Length() == 1)
				{
					sMonth = "0" + sMonth;
				}
				
				sDay = day.ToString();
				if (sDay.Length() == 1)
				{
					sDay = "0" + sDay;
				}
				
				sHour = hour.ToString();
				if (sHour.Length() == 1)
				{
					sHour = "0" + sHour;
				}
				
				sMinute = minute.ToString();
				if (sMinute.Length() == 1)
				{
					sMinute = "0" + sMinute;
				}
				
				sSecond = second.ToString();
				if (sSecond.Length() == 1)
				{
					sSecond = "0" + sSecond;
				}
				
				currentTime = sYear + "-" + sMonth + "-" + sDay + "_" + sHour + ":" + sMinute + ":" + sSecond;
				
				FPrintln(m_LogFile, "Log Created: " + currentTime);
				return true;
			}
			
			// Unable to create new Log file
			Print("Unable to create VehicleActivity.log file in Profile.");
			return false;
		}
		return false;
	}
	
	void Log(string text)
	{
		if (GetGame().IsMultiplayer())
		{
			// Getting Current Time and Date
			GetYearMonthDay(year, month, day);
			GetHourMinuteSecond(hour, minute, second);
			
			// Setting String for Time Variables for timestamp
			
			sHour = hour.ToString();
			if (sHour.Length() == 1)
			{
				sHour = "0" + sHour;
			}
			
			sMinute = minute.ToString();
			if (sMinute.Length() == 1)
			{
				sMinute = "0" + sMinute;
			}
			
			sSecond = second.ToString();
			if (sSecond.Length() == 1)
			{
				sSecond = "0" + sSecond;
			}
			
			currentTime = sHour + ":" + sMinute + ":" + sSecond + " | ";
			FPrintln(m_LogFile, currentTime + text);
		}
	}
}