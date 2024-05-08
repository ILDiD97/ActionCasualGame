using UnrealBuildTool; 

public class ActionCasualPlayer: ModuleRules 

{ 
        public ActionCasualPlayer(ReadOnlyTargetRules Target) : base(Target) 
        {
            PrivateDependencyModuleNames.AddRange(new string[] {"Core", "CoreUObject", "Engine", "EnhancedInput"}); 
        }
}