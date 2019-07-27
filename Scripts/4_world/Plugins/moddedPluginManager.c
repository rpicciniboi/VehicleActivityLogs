modded class PluginManager
{
	override void Init()
	{
		//----------------------------------------------------------------------
		// Register modules
		//----------------------------------------------------------------------
		//				Module Class Name 						Client	Server
		//----------------------------------------------------------------------
		if (GetGame().IsServer() || !GetGame().IsMultiplayer())
		{
			RegisterPlugin( "PluginVehicleLogs",					false,	true);
		}
		
		super.Init();
	}
}