#include "t_smart_ptr.h"
#include "t_polymorphism.h"
#include "t_overloading_operators.h"
#include "t_copy.h"
#include "t_move.h"
#include "t_template.h"
#include "t_mutable.h"
#include "t_mutex.h"
#include "t_conteiners.h"
#include "t_condition_variable.h"
#include "t_class.h"
#include "t_lambda.h"
#include "t_test.h"
#include "t_dp_factory.h"
#include "t_dp_adapter.h"
#include "t_dp_facade.h"
#include "t_dp_observer.h"
#include "t_type_conversions.h"
#include "t_constructor.h"
#include "t_dp_singleton.h"
#include "t_unique_ptr.h"
#include "t_shared_ptr.h"
//#include "t_boost_asio.h"
//#include "t_boost_signal.h"

int main()
{
    // basic elements
    //T_constructor::test();
    //T_copy::test();
    //T_move::test();
    //T_unique_ptr::test();
    //T_shared_ptr::test();
    //T_smart_ptr::test();
    //T_conteiners::test();
    //T_lambda::test();
    //T_type_conversions::test();

    // basic paradigm
    T_polymorphism::test();
    //T_overloading_operators::test();
    //T_template::test();
    //T_class::test();

    // paralel programming
    //T_mutex::test2();
    //T_condition_variable::test();

    // boost asio
    //T_boost_asio::test();

    // design patterns
    //T_dp_singleton::test();
    //T_dp_factory::test();
    //T_dp_adapter::test();
    //T_dp_facade::test();
    //T_dp_observer::test();
    //T_boost_signal::test();

    // some exercices
    //T_test::test();

    return 0;
}
