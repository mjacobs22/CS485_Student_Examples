#pragma once
#include "IEmployeeVisitor.h"
class PrintSalaryVisitor :
	public IEmployeeVisitor
{
public:
	PrintSalaryVisitor();
	virtual ~PrintSalaryVisitor();

	virtual void visit(Worker &rcWorker);
	virtual void visit(Manager &rcTheMan);
};

