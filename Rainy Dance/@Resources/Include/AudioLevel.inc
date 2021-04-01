[AudioOutput]
Measure=Plugin
Plugin=AudioLevel
PeakDecay=[#PeakDecay]
Group=Audio

[AudioMeasure]
Measure=Plugin
Plugin=AudioLevel
Parent=AudioOutput
Channel=Avg
Type=Peak

DynamicVariables=1
Group=Audio
UpdateDivider=5

IfCondition=([#PlayType]=2)
IfTrueAction=[!EnableMeasureGroup Audio]
IfFalseAction=[!DisableMeasureGroup Audio]

IfCondition2=([#Lock]=0) && (AudioMeasure<[#Threshold]) && ([#PlayType]=2)
IfTrueAction2=[!SetVariable State "waiting"][!SetVariable StateStorage "waiting"][!DisableMeasureGroup Random]

IfCondition3=([#Lock]=0) && (AudioMeasure>=[#Threshold]) && ([#PlayType]=2)
IfTrueAction3=[!SetVariable State [#Animation[#SetAnimation]]][!SetVariable StateStorage [#Animation[#SetAnimation]]][!CommandMeasure AnimationCalc "Reset"]

IfCondition4=([#Lock]=0) && (AudioMeasure>=[#Threshold]) && ([#PlayType]=2) && ([#Random]=1)
IfTrueAction4=[!SetVariable State [#Animation[#SetAnimation]]][!SetVariable StateStorage [#Animation[#SetAnimation]]][!EnableMeasureGroup Random][!UpdateMeasureGroup Random][!CommandMeasure AnimationCalc "Reset"]
