#pragma once
#include "recorder.hpp"
#include "audiostream.hpp"

namespace libvoip
{
	class Client
	{
	public:
		Client(const sf::Uint16 port);
		~Client();

		void Call(const sf::IpAddress adress);
		void Quit();
	private:
		NetworkRecorder m_recorder;
		NetworkAudioStream m_stream;
	};
}