modded class CarScript
{
	PluginVehicleLogs m_VehicleLogger = PluginVehicleLogs.Cast(GetPlugin(PluginVehicleLogs));
	void ~CarScript()
	{
		m_VehicleLogger.Log("Vehicle: " + this.GetDisplayName() + " despawned. Coords: " + this.GetPosition());
	}
}