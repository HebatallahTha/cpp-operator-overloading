//intro to overloading operators
#include <iostream>
class Job
{
	friend int operator+(int num,Job ajob);
	friend std::ostream& operator<<(std::ostream& out, const Job& aJob);
	friend std::istream& operator>>(std::istream& i,  Job& aJob);
	private:
		int jobNum;
		int jobTime;
		double hourlyRate;
	public:
		Job(int num,int time,double rate)
		{
			 jobNum=num;
			 jobTime=time;
			 hourlyRate=rate;
		}
		
		int getTime(){return jobTime;}
		int operator+(int num)
	{
		int totalTime=jobTime+num;
		return totalTime;
	}
	
	int operator-(int num)
	{
		
		return (jobTime-num);
	}
	
	int operator-(Job ajob)
	{
		
		return (this->jobTime-ajob.jobTime);
	}
	
	
	int operator+(Job ajob)
	{
		
		return (jobTime=ajob.jobTime);
	}
	
	void operator++()
	{
		hourlyRate++;
	} ///prefix ++x
	
	void operator++(int x)
	{
		hourlyRate++;
	} //postfix x++
	
	bool operator==(Job aJob)
	{
		return jobNum==aJob.jobNum;
		
		
	}
	
}; //endjobclass

int operator+(int num,Job ajob)
	{
		return  num +ajob.jobTime;
	}
	
std::ostream& operator<<(std::ostream& out, const Job& aJob)
{
	
	out << "\nJob number: "<<aJob.jobNum;
	out << "\nJob time: "<<aJob.jobTime;
	out << "\nJob rate: "<<aJob.hourlyRate;
	
	return out;

}

std::istream& operator>>(std::istream& i,  Job& aJob)
{
	std::cout<< "\nEnter Job number: ";
	i>>aJob.jobNum;
	std::cout<< "\nEnter time: ";
	i>>aJob.jobTime;
	std::cout<< "\nEnter rate: ";
	i>>aJob.hourlyRate;
	
	return i;

}
int main()
{
	Job jobA(111,10,10.50);
	Job jobB(222,20,20.50);


	std::cout<<"\nTime is: "<<jobA+15;
	std::cout<<"\nAlternitavley: "<<jobA.operator+(15);
	std::cout<<"\nLess! "<<jobA-5;
	
	std::cout<<"\nDifference :"<<jobA-jobB;
		Job jobC(333,30,30.50);

	std::cout<<"\nTwo jobs: "<<jobA+jobB;
	
	std::cout<<"\nAll three jobs: "<<jobA+jobB+jobC;
	std::cout<<jobA;

	std::cout<<jobA<<jobB<<jobC;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
	
	Job jobD(0,0,0);
	std::cin>>jobD;
	std::cout<<jobD;
	
	++jobD;
	
	std::cout<<jobD;
	jobD++;
	std::cout<<jobD;

 		
 	if (jobA==jobB)
 	{
 		std::cout<<"\nEqual";
	}
	else
	{
		std::cout<<"\nNot Equal";
	}
	
	return 0;
}
