// Can Gures, All Rights Reserved.


#include "AnimInstances/Hero/MyWarriorHeroAnimInstance.h"
#include "Characters/WarriorMainCharacter.h"



void UMyWarriorHeroAnimInstance::NativeInitializeAnimation()
{

	Super::NativeInitializeAnimation();
	if (OwningCharacter)
	{
		OwningHeroCharacter = Cast<AWarriorMainCharacter>(OwningCharacter);

	}
}

void UMyWarriorHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{

	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	if (bHasAcceleration)
	{
		IdleElapsedTime = 0.f;
		bShouldEnterRelaxState = false;

	}
	else
	{
		IdleElapsedTime += DeltaSeconds;
		bShouldEnterRelaxState = (IdleElapsedTime >= EnterRelaxStateFreshold);
	

	}

}
