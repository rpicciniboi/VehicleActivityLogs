modded class ActionStartEngine
{
	PluginVehicleLogs m_VehicleLogger = PluginVehicleLogs.Cast(GetPlugin(PluginVehicleLogs));

	override void OnFinishProgressServer(ActionData action_data)
	{
		m_VehicleLogger.Log("Player " + action_data.m_Player.GetIdentity().GetName() + " (" + action_data.m_Player.GetPosition() + " steam64id=" + action_data.m_Player.GetIdentity().GetPlainId() + ") stopped " + action_data.m_MainItem.GetDisplayName());

        super.OnFinishProgressServer(action_data);
    }
}