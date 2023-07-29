# Credit/Debit Card Type Identification Utility Software

## Introduction

The Credit/Debit Card Type Identification Utility Software is a command-line utility developed in the C programming language. It allows users to determine the type of credit or debit card based on the provided card number. The software employs the Luhn algorithm to validate the card number's integrity and subsequently identifies the card type, such as Visa or MasterCard.

## Features

- Accurate card type identification using Luhn algorithm validation.
- Supports common credit/debit card types such as Visa, MasterCard, and American Express.
- Simple graphical interface for easy interaction.
- Integration of the GTK 3.0 library for a graphical user interface (GUI) version.

## Functions

The utility software provides the following essential functions:

1. `bool validateCreditCard(const char *cardNumber)`: Validates the card number using the Luhn algorithm and returns a boolean value indicating whether the card number is valid or not.

2. `const char* detectManufacturer()`: Determines the card type based on the first few digits of the card number. It identifies common card types such as Visa, MasterCard, American Express, etc.

3. `gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Enter Credit Card Number")`: Collects the credit/debit card number from the user via the user interface.

4. `int main()`: Orchestrates the execution of the utility software, calling the user input function, Luhn algorithm function, card type identification function, exit function and check button click function. Displays the result, indicating the card type or an error message for an invalid card number.

## Installation

To use the Credit/Debit Card Type Identification Utility Software, follow these steps:

1. Clone the repository or download the source code to your local machine.

2. Compile the source code using a C compiler with the required libraries (for the GUI version).

3. Run the executable file and follow the instructions on the command-line or graphical interface.

## Usage

1. For the GUI version (if available), launch the compiled GUI application, input your card number in the provided field, and click the "Check" button. The software will display the card type or an error message in the same window.

## Dependencies

- C programming language
- Standard C libraries
- [GTK 3.0](https://www.gtk.org/) (required for the GUI version)

## License

****open source****

## Contributions

Contributions to the Credit/Debit Card Type Identification Utility Software are welcome! If you find any issues or have suggestions for improvements, feel free to open an issue or create a pull request.

## Acknowledgments

- The open-source community for providing the GTK 3.0 library, enabling the creation of the graphical interface.
