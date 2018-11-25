#pragma once
#include <iostream>
#include <SFML/Network.hpp>
#include <unordered_map>

class PortScanner
{
public:
	PortScanner();
	~PortScanner();

public:
	void run();

private:
	void scan(unsigned short startRange, unsigned short endRange);
	void printOpenPorts();
	void printClosedPorts();

private:
	std::unordered_map<unsigned short, bool> ports;
	sf::IpAddress local=sf::IpAddress::getLocalAddress();
	bool running;
};