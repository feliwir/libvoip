#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>

namespace libvoip
{
	const sf::Uint8 audioData = 1;
	const sf::Uint8 endOfStream = 2;

	class NetworkRecorder : public sf::SoundRecorder
	{
	public:

		NetworkRecorder(const sf::IpAddress& host, unsigned short port);
		~NetworkRecorder();

	private:
		virtual bool onStart();	
		virtual bool onProcessSamples(const sf::Int16* samples, std::size_t sampleCount);
		virtual void onStop();

		sf::IpAddress  m_host;   ///< Address of the remote host
		unsigned short m_port;   ///< Remote port
		sf::TcpSocket  m_socket; ///< Socket used to communicate with the server
	};
}