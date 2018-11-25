#include "PortScanner.h"

PortScanner::PortScanner()
	:running(true)
{

}

PortScanner::~PortScanner()
{

}

void PortScanner::run()
{
	unsigned short start, end;
	do
	{
		std::cout << "Enter port range to scan: ";
		std::cin >> start;
		std::cin >> end;

		scan(start, end);
		printOpenPorts();
		printClosedPorts();

		ports.clear();

		system("pause");
		system("cls");

	} while (running);
}

void PortScanner::scan(unsigned short startRange, unsigned short endRange)
{
	sf::TcpSocket socket;
	for (int i = startRange; i <= endRange; i++)
	{
		if (socket.connect(local, i, sf::seconds(1)) == sf::Socket::Done)
		{
			ports[i] = true; //mark port as open
		}
		else
		{
			ports[i] = false; //mark as closed
		}

	}
}

void PortScanner::printOpenPorts()
{
	std::cout << "Open ports: " << std::endl;
	for (auto it = ports.begin(); it != ports.end(); it++)
	{
		if (it->second == true)
			std::cout << it->first << std::endl;
	}
	std::cout << "\n";
}

void PortScanner::printClosedPorts()
{
	std::cout << "Closed ports: " << std::endl;
	for (auto it = ports.begin(); it != ports.end(); it++)
	{
		if (it->second == false)
			std::cout << it->first << std::endl;
	}
	std::cout << "\n";
}
