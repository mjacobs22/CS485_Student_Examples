#include "PrintSalaryVisitor.h"



PrintSalaryVisitor::PrintSalaryVisitor()
{
}


PrintSalaryVisitor::~PrintSalaryVisitor()
{
}

void PrintSalaryVisitor::visit(Worker & rcWorker)
{
	if (rcWorker.getSalary() % 2 != 0)
	{
		std::cout << rcWorker << std::endl;
	}
}

void PrintSalaryVisitor::visit(Manager & rcTheMan)
{
	if (rcTheMan.getSalary() % 2 == 0)
	{
		std::cout << rcTheMan << std::endl;
	}
}
