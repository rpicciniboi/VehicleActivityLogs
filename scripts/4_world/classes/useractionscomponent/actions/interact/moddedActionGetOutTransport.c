modded class ActionGetOutTransport
{
	PluginVehicleLogs m_VehicleLogger = PluginVehicleLogs.Cast(GetPlugin(PluginVehicleLogs));

    override void OnStartServer(ActionData action_data)
    {
		m_VehicleLogger.Log("Player " + action_data.m_Player.GetIdentity().GetName() + " (" + action_data.m_Player.GetPosition() + " steam64id=" + action_data.m_Player.GetIdentity().GetPlainId() + ") Exited: " + action_data.m_MainItem.GetDisplayName());

        super.OnStartServer(action_data);
    }
}