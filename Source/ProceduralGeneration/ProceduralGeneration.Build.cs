using UnrealBuildTool; 

public class ProceduralGeneration: ModuleRules 

{ 

        public ProceduralGeneration(ReadOnlyTargetRules Target) : base(Target) 

        {
            PrivateDependencyModuleNames.AddRange(new string[] {"Core", "CoreUObject", "Engine"});
        }
}  