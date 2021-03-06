#include <iostream>
#include <string>


const double THRESHOLD = 10000.0;


struct Contribution
{
	std::string name = "";
	double contributionAmount = 0.0;
};


int main()
{
	std::cout << "Contribution tracker for the Society for the Preservation of Rightful Influence" << std::endl;
	std::cout << "Enter the number of contributors you want to add: ";


	unsigned short contributorNumber;
	std::cin >> contributorNumber;

	std::cin.get();


	Contribution* contributions = new Contribution[contributorNumber];


	for (int i = 0; i < contributorNumber; i++)
	{
		std::cout << "\nPlease enter the name of contributor #" << (i + 1) << ": ";
		getline(std::cin, contributions[i].name);

		std::cout << "Please enter the amount " << contributions[i].name << " contributed: $";
		std::cin >> contributions[i].contributionAmount;

		std::cin.get();
	}


	std::cout.precision(2);

	// GRAND PATRONS WITH CONTRIBUTIONS GREATER THAN THRESHOLD'S VALUE
	bool contributionWasMade = false;

	std::cout << "\n\nGrand Patrons" << std::endl;
	std::cout << "=============" << std::endl;

	for (int i = 0; i < contributorNumber; i++)
	{
		if (contributions[i].contributionAmount > THRESHOLD)
		{
			contributionWasMade = true;
			std::cout << contributions[i].name << " - $" << std::fixed << contributions[i].contributionAmount << std::endl;
		}
	}

	if (!contributionWasMade)
		std::cout << "None." << std::endl;


	// PATRONS WITH CONTRIBUTIONS SMALLER THAN THRESHOLD'S VALUE
	contributionWasMade = false; // reuse variable

	std::cout << "\n\nPatrons" << std::endl;
	std::cout << "=======" << std::endl;

	for (int i = 0; i < contributorNumber; i++)
	{
		if (contributions[i].contributionAmount <= THRESHOLD)
		{
			contributionWasMade = true;
			std::cout << contributions[i].name << " - $" << std::fixed << contributions[i].contributionAmount << std::endl;
		}
	}

	if (!contributionWasMade)
		std::cout << "None." << std::endl;


	std::cin.get();

	delete[] contributions;

	return 0;
}