#ifndef COMPANIES101_COMPANY_HPP
#define COMPANIES101_COMPANY_HPP
#include "Department.hpp"
#include "Host.hpp"
#include <vector>
namespace companies101 {
class Visitor;
class MutateVisitor;

class Company : public Host {
public:
    Company(const std::string            & name        = "",
            const std::vector<Department>& departments = {});

    const std::string            & getName       () const;
    const std::vector<Department>& getDepartments() const;

    void setName       (const std::string            & name       );
    void setDepartments(const std::vector<Department>& departments);

    std::vector<Department>& getMutableDepartments();

    void accept(const Visitor      & visitor) const override;
    void accept(const MutateVisitor& visitor)       override;

private:
    std::string name;
    std::vector<Department> departments;
};

}
#endif

