modded class ActionStopEngine
{
	PluginVehicleLogs m_VehicleLogger = PluginVehicleLogs.Cast(GetPlugin(PluginVehicleLogs));

	override void OnExecuteServer(ActionData action_data)
	{
		if (GetGame().IsServer())
		{
			m_VehicleLogger.Log("Player " + action_data.m_Player.GetIdentity().GetName() + " (" + action_data.m_Player.GetPosition() + " steam64id=" + action_data.m_Player.GetIdentity().GetPlainId() + ") stopped " + action_data.m_MainItem.GetDisplayName());
		}

        super.OnExecuteServer(action_data);
    }
}