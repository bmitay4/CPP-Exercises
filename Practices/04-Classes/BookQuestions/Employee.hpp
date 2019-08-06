//Employee header file
class Employee{
private:
  int itsAge;
  int itsYearOfService;
  int itsSalary;
public:
  Employee();
  Employee(int age, int yearsOfService, int salary);
  ~Employee(){
  }

  int getAge() const {return itsAge;}
  int getYearsOfService() const {return itsYearOfService;}
  int getSalary() const {return itsSalary;}

  void getFullDetails(Employee e) const;
  void setAge(int value) {itsAge = value;}
  void setYearsOfService(int value) {itsYearOfService = value;}
  void setSalary(int value) {itsSalary = value;}
};
