modded class PlayerBase
{
	PluginVehicleLogs m_VehicleLogger = PluginVehicleLogs.Cast(GetPlugin(PluginVehicleLogs));
	
	override void OnVehicleEnter()
	{
        super.OnVehicleEnter();
		if (GetGame().IsServer() && GetIdentity())
		{
			HumanCommandVehicle vehCommand = GetCommand_Vehicle();
			if (vehCommand)
			{
				Transport trans = vehCommand.GetTransport();
				if (trans)
					m_VehicleLogger.Log("Player " + GetIdentity().GetName() + " (" + GetPosition() + " steam64id=" + GetIdentity().GetPlainId() + ") entered " + trans.GetDisplayName() + " (" + trans + ")");
			}
		}
    }
	
	override void OnVehicleExit()
	{
        super.OnVehicleExit();
		if (GetGame().IsServer() && GetIdentity())
		{
			m_VehicleLogger.Log("Player " + GetIdentity().GetName() + " (" + GetPosition() + " steam64id=" + GetIdentity().GetPlainId() + ") exited vehicle");
		}
    }
};