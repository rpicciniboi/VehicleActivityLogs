class CfgPatches
{
	class VehicleActivityLogs_scripts
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={};
	};
};

class CfgMods
{
	class VehicleActivityLogs
	{
	    dir = "VehicleActivityLogs";
	    picture = "";
	    action = "";
	    hideName = 1;
	    hidePicture = 1;
	    name = "Vehicle Activity Logs";
	    credits = "Cleetus";
	    author = "Cleetus";
	    authorID = "0";
	    version = "1.0";
	    extra = 0;
	    type = "mod";

	    dependencies[] = {"World"};

	    class defs
	    {
			class worldScriptModule
            {
                value = "";
                files[] = {"VehicleActivityLogs/scripts/4_World"};
            };
        };
    };
};
