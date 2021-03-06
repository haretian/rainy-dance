[mState]
Measure=Plugin
Plugin=WebNowPlaying

PlayerType=State
DynamicVariables=1

OnChangeAction=[!UpdateMeter *] [!UpdateMeter *] [!Redraw]

IfCondition=([#PlayType]=1)
IfTrueAction=[!EnableMeasure mState]
IfFalseAction=[!DisableMeasure mState]

IfCondition2=([#Lock]=0) && (mState=0) || (mState=2) && ([#PlayType]=1)
IfTrueAction2=[!SetVariable State "waiting"][!SetVariable StateStorage "waiting"][!DisableMeasureGroup Random]

IfCondition3=([#Lock]=0) && (mState<>0) && (mState<>2) && ([#PlayType]=1)
IfTrueAction3=[!SetVariable State [#Animation[#SetAnimation]]][!SetVariable StateStorage [#Animation[#SetAnimation]]][!CommandMeasure AnimationCalc "Reset"]

IfCondition4=([#Lock]=0) && (mState<>0) && (mState<>2) && ([#PlayType]=1) && ([#Random]=1)
IfTrueAction4=[!SetVariable State [#Animation[&RandomCalc]]][!SetVariable StateStorage [#Animation[#SetAnimation]]][!EnableMeasureGroup Random][!UpdateMeasureGroup Random][!CommandMeasure AnimationCalc "Reset"]
