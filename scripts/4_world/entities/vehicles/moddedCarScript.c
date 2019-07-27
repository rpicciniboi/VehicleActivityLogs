modded class CarScript
{
	PluginVehicleLogs m_VehicleLogger = PluginVehicleLogs.Cast(GetPlugin(PluginVehicleLogs));
	
    void CarScript()
    {
        if (GetGame().IsServer())
        {
            GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.LogPosition, 3, false, true);
        }
    }

	void ~CarScript()
	{
        if (GetGame().IsServer())
            LogPosition(false);
	}

    void LogPosition(bool init)
    {
		string msg = "initialized";
		if (!init)
			msg = "closed or destroyed";

        PluginVehicleLogs m_VehicleLogger = PluginVehicleLogs.Cast(GetPlugin(PluginVehicleLogs));
        m_VehicleLogger.Log(GetDisplayName() + " (" + this + " - pos " + GetPosition() + ") " + msg);
    }
}