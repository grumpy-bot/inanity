#include "AlPlayer.hpp"
#include "AlDevice.hpp"
#include "AlSystem.hpp"
#include "../Exception.hpp"

BEGIN_INANITY_AUDIO

AlPlayer::AlPlayer(ptr<AlDevice> device)
: device(device)
{
	BEGIN_TRY();

	alGenSources(1, &source);
	AlSystem::CheckErrors("Can't gen source");

	END_TRY("Can't create OpenAL player");
}

AlPlayer::~AlPlayer()
{
	if(source)
		alDeleteSources(1, &source);
}

void AlPlayer::SetPosition(const Math::vec3& position)
{
	alSource3f(source, AL_POSITION, position.x, position.y, position.z);
	AlSystem::CheckErrors("Can't set OpenAL player position");
}

void AlPlayer::SetDirection(const Math::vec3& direction)
{
	alSource3f(source, AL_DIRECTION, direction.x, direction.y, direction.z);
	AlSystem::CheckErrors("Can't set OpenAL player direction");
}

void AlPlayer::SetVelocity(const Math::vec3& velocity)
{
	alSource3f(source, AL_VELOCITY, velocity.x, velocity.y, velocity.z);
	AlSystem::CheckErrors("Can't set OpenAL player velocity");
}

END_INANITY_AUDIO
