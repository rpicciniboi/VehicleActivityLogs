modded class ActionStopEngine
{
	PluginVehicleLogs m_VehicleLogger = PluginVehicleLogs.Cast(GetPlugin(PluginVehicleLogs));

	override void OnEndServer(ActionData action_data)
	{
        super.OnEndServer(action_data);
		if (action_data.m_Player && action_data.m_Player.GetIdentity())
		{
			HumanCommandVehicle vehCommand = action_data.m_Player.GetCommand_Vehicle();
			if (vehCommand)
			{
				Transport trans = vehCommand.GetTransport();
				if (trans)
					m_VehicleLogger.Log("Player " + action_data.m_Player.GetIdentity().GetName() + " (" + action_data.m_Player.GetPosition() + " steam64id=" + action_data.m_Player.GetIdentity().GetPlainId() + ") stopped " + trans.GetDisplayName() + " (" + trans + ")");
			}
		}
    }
}