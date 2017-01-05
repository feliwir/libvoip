#include "recorder.hpp"
using namespace libvoip;

NetworkRecorder::NetworkRecorder(const sf::IpAddress& host, unsigned short port) :
	m_host(host),
	m_port(port)
{
}

NetworkRecorder::~NetworkRecorder()
{
	// Make sure to stop the recording thread
	stop();
}

bool NetworkRecorder::onStart()
{
	if (m_socket.connect(m_host, m_port) == sf::Socket::Done)
	{
		std::cout << "Connected to server " << m_host << std::endl;
		return true;
	}
	else
	{
		return false;
	}
}


bool NetworkRecorder::onProcessSamples(const sf::Int16* samples, std::size_t sampleCount)
{
	// Pack the audio samples into a network packet
	sf::Packet packet;
	packet << audioData;
	packet.append(samples, sampleCount * sizeof(sf::Int16));

	// Send the audio packet to the server
	return m_socket.send(packet) == sf::Socket::Done;
}

void NetworkRecorder::onStop()
{
	// Send a "end-of-stream" packet
	sf::Packet packet;
	packet << endOfStream;
	m_socket.send(packet);

	// Close the socket
	m_socket.disconnect();
}