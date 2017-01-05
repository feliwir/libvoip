#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>

namespace libvoip
{
	const sf::Uint8 audioData = 1;
	const sf::Uint8 endOfStream = 2;

	class NetworkAudioStream : public sf::SoundStream
	{
	public:
		NetworkAudioStream();
		void start(unsigned short port);
	private:
		virtual bool onGetData(sf::SoundStream::Chunk& data);
		virtual void onSeek(sf::Time timeOffset);
		void receiveLoop();

		sf::TcpListener        m_listener;
		sf::TcpSocket          m_client;
		sf::Mutex              m_mutex;
		std::vector<sf::Int16> m_samples;
		std::vector<sf::Int16> m_tempBuffer;
		std::size_t            m_offset;
		bool                   m_hasFinished;
	};
}