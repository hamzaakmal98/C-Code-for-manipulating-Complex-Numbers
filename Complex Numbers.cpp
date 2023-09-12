#include <iostream>

using namespace std;

class Integer
{
private:
	int object_data;
public:
	Integer()
	{
		object_data = 0;
	}
	Integer(int working_data)
	{
		object_data = working_data;
	}
	void setter(int working_data)
	{
		object_data = working_data;
	}
	int getter()
	{
		return object_data;
	}
	virtual void Add(Integer * working_data)
	{
		*this = working_data->getter() + object_data;
	} 
	virtual void Subtract(Integer * working_data)
	{
		*this = working_data->getter() - object_data;
	}
	virtual void Multiply(Integer * working_data)
	{
		*this = working_data->getter() * object_data;
	}
	virtual void Display()
	{
		cout << object_data << endl;
	}
};

class Rational : public Integer
{
private:
	int denominator;    
public:
	Rational(int input_numerator, int input_denominator)
	{
		setter(input_numerator);
		denominator = input_denominator;
	}
	void setDenominator(int working_data)
	{
		denominator = working_data;
	}
	void Add(Integer *working_data)
	{
		Rational * numA = dynamic_cast<Rational*>(working_data);
		int numB;
		int num2;
		// cout << numA -> denominator << endl;
		// cout << numA -> getter() << endl;
		numB =  (numA -> denominator) * getter() + denominator * (numA->getter()) ;
		// cout << denominator << endl;
		num2 = denominator + numA->denominator;
		denominator = numA -> denominator * denominator;
		setter(numB);
	}
	void Subtract(Integer *working_data)
	{
		Rational * numA = dynamic_cast<Rational*>(working_data);
		int numB;
		int num2;
		// cout << numA -> denominator << endl;
		// cout << numA -> getter() << endl;
		numB =  (numA -> denominator) * getter() - denominator * (numA->getter()) ;
		// cout << denominator << endl;
		num2 = denominator + numA->denominator;
		denominator = numA -> denominator * denominator;
		setter(numB);
	}
	void Multiply(Integer *working_data)
	{
		Rational * numA = dynamic_cast<Rational*>(working_data);
		int numB;
		int num2;
		// cout << numA -> denominator << endl;
		// cout << numA -> getter() << endl;
		numB =   getter() * (numA->getter()) ;
		// cout << denominator << endl;
		num2 = denominator + numA->denominator;
		denominator = numA -> denominator * denominator;
		setter(numB);
	}
	void Display()
	{
		cout << getter() << "/" << denominator << endl << endl;
	}
};

class Complex : public Integer
{
private:
	int imaginary;
public:
	Complex(int r1, int data_imaginary)
	{
		setter(r1);
		imaginary = data_imaginary;
	}
	Complex()
	{
		setter(0);
		imaginary = 0;
	}
	void Add(Integer *working_data)
	{
		Complex *data_imaginary = dynamic_cast<Complex*>(working_data);
		int r1;
		int imaginaryFinal;
		cout << imaginary << endl;
		r1 = getter() + data_imaginary->getter();
		// cout << (data_imaginary -> imaginary) << endl;
		// imaginary = (data_imaginary -> imaginary) +;
		setter(r1);
	}
	void Subtract(Integer *working_data)
	{
		Complex *data_imaginary = dynamic_cast<Complex*>(working_data);
		int r1;
		int imaginary;
		r1 = getter() - data_imaginary->getter();
		imaginary = imaginary - data_imaginary->imaginary;
		setter(r1);
	}
	void Multiply(Integer *working_data)
	{
		Complex *data_imaginary = dynamic_cast<Complex*>(working_data);
		int r1;
		int imaginary;
		r1 = getter() * data_imaginary->getter();
		imaginary = imaginary * data_imaginary->imaginary;
		imaginary = imaginary;
		setter(r1);
	}
	void Display()
	{
		cout << getter() << " + " << imaginary << "i" << endl;
	}
};

int main()
{
	int choice;
	while(true)
	{
		cout << "Please select an option." << endl;
		cout << "\t1: for Integer Calculator" << endl;
        cout << "\t2: for Complex Calculator" << endl;
		cout << "\t3: for Rational Calculator" << endl;
		cout << "\t4: to exit the program" << endl;
		cin >> choice;
		if(choice == 1)
		{
			cout << "Please enter first Integer : ";
			int numB,num2,sum,difference,product;
			cin >> numB;

			cout << "Please enter second Integer : " ;
			cin >> num2;
		
			cout << endl << endl;
			cout << "Please choose an option." << endl;
			cout << "\t1: Add" << endl;
			cout << "\t2: Subtract" << endl;
			cout << "\t3: Multiply" << endl;
			cout << endl;
			int subChoice;
			cin >> subChoice;
			if(subChoice == 1)
			{
				sum = numB + num2;
				cout << "The sum is : " << sum << endl;
			}
			else if(subChoice == 2)
			{
				difference = numB - num2;
				cout << "The difference is : "  << difference << endl ;
			}
			else if(subChoice == 3)
			{
				product = numB * num2;
				cout << "The product is : " << product << endl ;
			}
		}

		else if(choice == 2)
		{
            int r1,r2,i1,i2;
			cout << "Enter real part of first number : ";
			cin >> r1;
			cout << "Enter imaginary part of first number : ";
			cin >> i1;
			cout << "Enter real part of second number : ";
			cin >> r2;
			cout << "Enter imaginary part of second number : ";
			cin >> i2;

			Integer *working_data = new Complex(r1 , i1);
			Integer *fun2 = new Complex(r2 , i2);

			cout << "Please select an option." << endl;
			cout << "\t1: Add" << endl;
			cout << "\t2: Subtract" << endl;
			cout << "\t3: Multiply" << endl;

			int subChoice2;
			cin >> subChoice2;
			if(subChoice2 == 1)
			{
				working_data->Add(fun2);
				cout << "The sum is : " ;
				working_data->Display();
			}
			if(subChoice2 == 2)
			{
				working_data->Subtract(fun2);
				cout << "The difference is : " ;
				working_data->Display();
			}
			if(subChoice2 == 3)
			{
				working_data->Multiply(fun2);
				cout << "The product is : ";
				working_data->Display();
			}
			
		}
		else if(choice == 3)
		{
            int numA,input_denominator,numB,input_denominatorB;
			cout << "Enter numerator of first number : " ;
			cin >> numA;
			cout << "Enter denominator'of first number : ";
			cin >> input_denominator;
			cout << "Enter numerator of second number : " ;
			cin >> numB;
			cout << "Enter denominator'of second number : ";
			cin >> input_denominatorB;

			Integer *working_data = new Rational(numA , input_denominator);
			Integer *fun = new Rational(numB , input_denominatorB);

			cout << "Please select an option." << endl;
			cout << "\t1: Add" << endl;
			cout << "\t2: Subtract" << endl;
			cout << "\t3: Multiply" << endl;

			int subChoice2;
			cin >> subChoice2;

			if(subChoice2 == 1)
			{
				working_data->Add(fun);
				cout << "The sum is : ";
				working_data->Display();
			}
			if(subChoice2 == 2)
			{
				working_data->Subtract(fun);
				cout << "The difference is : " ;
				working_data->Display();
			}
			if(subChoice2 == 3)
			{
				working_data->Multiply(fun);
				cout << "The product is : " ;
				working_data->Display();
			}
		}
		else
		{
			break;
		}
	}
	return 0;	
}