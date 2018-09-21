//  Copyright John Maddock 2015.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifdef _MSC_VER
#  pragma warning (disable : 4224)
#endif

#include <boost/math/special_functions/jacobi_elliptic.hpp>
#include <boost/array.hpp>
#include <boost/lexical_cast.hpp>
#include "../../test/table_type.hpp"
#include "table_helper.hpp"
#include "performance.hpp"
#include <iostream>

typedef double T;
#define SC_(x) static_cast<double>(x)
    static const boost::array<boost::array<T, 5>, 36> data1 = {{
        {{ SC_(0.0), SC_(0.0), SC_(0.0), SC_(1.0), SC_(1.0) }},
        {{ ldexp(T(1), -25), ldexp(T(1), -25), SC_(2.98023223876953080883700663838486782870427050521881839342311e-8), SC_(0.99999999999999955591079014993741669975171697261290223678373), SC_(0.99999999999999999999999999999960556954738949421406900774443) }},
        {{ -ldexp(T(1), -25), ldexp(T(1), -25), SC_(-2.98023223876953080883700663838486782870427050521881839342311e-8), SC_(0.99999999999999955591079014993741669975171697261290223678373), SC_(0.99999999999999999999999999999960556954738949421406900774443) }},
        {{ SC_(0.25), ldexp(T(1), -25), SC_(0.247403959254522927383635623557663763268693729825996390997241), SC_(0.968912421710644784709721529742747886950140086772629513814665), SC_(0.99999999999999997281786831901333837240938011109848356555885) }},
        {{ SC_(-0.25), ldexp(T(1), -25), SC_(-0.247403959254522927383635623557663763268693729825996390997241), SC_(0.968912421710644784709721529742747886950140086772629513814665), SC_(0.99999999999999997281786831901333837240938011109848356555885) }},
        {{ SC_(1.25), ldexp(T(1), -25), SC_(0.948984619355586147780156037971989352776684194861616269831136), SC_(0.315322362395268865789580233344649598639316847638615703458263), SC_(0.99999999999999960006577747263860127231780811081154547949983) }},
        {{ SC_(-1.25), ldexp(T(1), -25), SC_(-0.948984619355586147780156037971989352776684194861616269831136), SC_(0.315322362395268865789580233344649598639316847638615703458263), SC_(0.99999999999999960006577747263860127231780811081154547949983) }},
        {{ SC_(25.0), ldexp(T(1), -25), SC_(-0.132351750097778560056127137329035522219365438979106560464704), SC_(0.991202811863472859528158119981178957382802975691690722810123), SC_(0.99999999999999999222089563757583834413059580275315226870704) }},
        {{ SC_(-25.0), ldexp(T(1), -25), SC_(0.132351750097778560056127137329035522219365438979106560464704), SC_(0.991202811863472859528158119981178957382802975691690722810123), SC_(0.99999999999999999222089563757583834413059580275315226870704) }},
        {{ ldexp(T(1), -25), SC_(0.5), SC_(2.98023223876953058825550995757802173334628440851964836958219e-8), SC_(0.99999999999999955591079014993744956895610118130967536624417), SC_(0.99999999999999988897769753748438088116649141278818704012037) }},
        {{ -ldexp(T(1), -25), SC_(0.5), SC_(-2.98023223876953058825550995757802173334628440851964836958219e-8), SC_(0.99999999999999955591079014993744956895610118130967536624417), SC_(0.99999999999999988897769753748438088116649141278818704012037) }},
        {{ SC_(0.25), SC_(0.5), SC_(0.246781405136141600483623741101255389743847413013817188632739), SC_(0.969071172865559727608777289021929824625726812182428398055476), SC_(0.992358168465276394946615469032829292963938826683866720698130) }},
        {{ SC_(-0.25), SC_(0.5), SC_(-0.246781405136141600483623741101255389743847413013817188632739), SC_(0.969071172865559727608777289021929824625726812182428398055476), SC_(0.992358168465276394946615469032829292963938826683866720698130) }},
        {{ SC_(1.25), SC_(0.5), SC_(0.928561236426319775700204388269999130782711902203415239399579), SC_(0.371179242693370810357222594552131893184749696381729988511999), SC_(0.885688154799196841458565445994481097477880319663264816077719) }},
        {{ SC_(-1.25), SC_(0.5), SC_(-0.928561236426319775700204388269999130782711902203415239399579), SC_(0.371179242693370810357222594552131893184749696381729988511999), SC_(0.885688154799196841458565445994481097477880319663264816077719) }},
        {{ SC_(25.0), SC_(0.5), SC_(-0.969223071486651608400225080456020493867827336842041561445359), SC_(-0.246184154035106463351874891855925292474628176040625311168501), SC_(0.874729477852721764836147376110255133761608728373832418508248) }},
        {{ SC_(-25.0), SC_(0.5), SC_(0.969223071486651608400225080456020493867827336842041561445359), SC_(-0.246184154035106463351874891855925292474628176040625311168501), SC_(0.874729477852721764836147376110255133761608728373832418508248) }},
        {{ ldexp(T(1), -25), 1 - ldexp(T(1), -9), SC_(2.98023223876953036939562331632512854347569015560128614888589e-8), SC_(0.99999999999999955591079014993754766348947956082687878223721), SC_(0.99999999999999955764381956001984590118394542979655101564079) }},
        {{ -ldexp(T(1), -25), 1 - ldexp(T(1), -9), SC_(-2.98023223876953036939562331632512854347569015560128614888589e-8), SC_(0.99999999999999955591079014993754766348947956082687878223721), SC_(0.99999999999999955764381956001984590118394542979655101564079) }},
        {{ SC_(0.25), 1 - ldexp(T(1), -9), SC_(0.244928335616519632082236089277654937383208524525331032303082), SC_(0.969541185516180906431546524888118346090913555188425579774305), SC_(0.969661908643964623248878987955178702010392829596222190545649) }},
        {{ SC_(-0.25), 1 - ldexp(T(1), -9), SC_(-0.244928335616519632082236089277654937383208524525331032303082), SC_(0.969541185516180906431546524888118346090913555188425579774305), SC_(0.969661908643964623248878987955178702010392829596222190545649) }},
        {{ SC_(1.25), 1 - ldexp(T(1), -9), SC_(0.848768940045053312079390719205939167551169094157365783446523), SC_(0.528763923140371497228677918580246099580380684604621321430057), SC_(0.531415689278260818860813380561526095359692710060403584603095) }},
        {{ SC_(-1.25), 1 - ldexp(T(1), -9), SC_(-0.848768940045053312079390719205939167551169094157365783446523), SC_(0.528763923140371497228677918580246099580380684604621321430057), SC_(0.531415689278260818860813380561526095359692710060403584603095) }},
        {{ SC_(25.0), 1 - ldexp(T(1), -9), SC_(-0.0252326124525503880903568715488227138184083895871544015366337), SC_(-0.999681606947341709011836635135181960590782564534371631099332), SC_(0.999682849652724146508471774051629114156076052044812654903417) }},
        {{ SC_(-25.0), 1 - ldexp(T(1), -9), SC_(0.0252326124525503880903568715488227138184083895871544015366337), SC_(-0.999681606947341709011836635135181960590782564534371631099332), SC_(0.999682849652724146508471774051629114156076052044812654903417) }},

        // Try modulus > 1
        {{ ldexp(T(1), -25), SC_(1.5), SC_(2.98023223876952981622027157475276613133414644789222481971590e-8), SC_(0.999999999999999555910790149937712522591174851747994454928040), SC_(0.999999999999999000799277837359575841918151654603571877092161) }},
        {{ -ldexp(T(1), -25), SC_(1.5), SC_(-2.98023223876952981622027157475276613133414644789222481971590e-8), SC_(0.999999999999999555910790149937712522591174851747994454928040), SC_(0.999999999999999000799277837359575841918151654603571877092161) }},
        {{ SC_(0.25), SC_(1.5), SC_(0.241830488135945315134822478837394038661484435596992059686086), SC_(0.970318512143270619246031961334217540099946232418710982266812), SC_(0.931888155181641649031244632258710371461078255228024421800363) }},
        {{ SC_(-0.25), SC_(1.5), SC_(-0.241830488135945315134822478837394038661484435596992059686086), SC_(0.970318512143270619246031961334217540099946232418710982266812), SC_(0.931888155181641649031244632258710371461078255228024421800363) }},
        {{ SC_(1.25), SC_(1.5), SC_(0.665875890711922169121186264316618499018039094009893317545462), SC_(0.746062529663971452521312655373498959968622875614588791642250), SC_(-0.0486921028438866868299166778939466685768843580182675008164949) }},
        {{ SC_(-1.25), SC_(1.5), SC_(-0.665875890711922169121186264316618499018039094009893317545462), SC_(0.746062529663971452521312655373498959968622875614588791642250), SC_(-0.0486921028438866868299166778939466685768843580182675008164949) }},
        {{ SC_(25.0), SC_(1.5), SC_(0.618665338981368217712277210270169521641154921220796362724248), SC_(0.785654630447163313102421517325310755764805805534154371583941), SC_(0.372585153048138377269609818284480926623056458773704266654150) }},
        {{ SC_(-25.0), SC_(1.5), SC_(-0.618665338981368217712277210270169521641154921220796362724248), SC_(0.785654630447163313102421517325310755764805805534154371583941), SC_(0.372585153048138377269609818284480926623056458773704266654150) }},

        // Special Values:
        {{ SC_(0.0), SC_(0.5), SC_(0.0), SC_(1.0), SC_(1.0) }},
        {{ SC_(5.0), SC_(0.0), SC_(-0.958924274663138468893154406155993973352461543964601778131672), SC_(0.283662185463226264466639171513557308334422592252215944930359), SC_(1.0) }},
        {{ SC_(5.0), SC_(1.0), SC_(0.999909204262595131210990447534473021089812615990547862736429), SC_(0.0134752822213045573055191382448821552908373539417006868332819), SC_(0.0134752822213045573055191382448821552908373539417006868332819) }},
    }};


int main()
{
#include "jacobi_elliptic.ipp"
#include "jacobi_elliptic_small.ipp"
#include "jacobi_near_1.ipp"
#include "jacobi_large_phi.ipp"

   add_data(data1);
   add_data(jacobi_elliptic);
   add_data(jacobi_elliptic_small);
   add_data(jacobi_near_1);
   add_data(jacobi_large_phi);

   unsigned data_total = data.size();


   std::cout << "Screening Boost data:\n";
   screen_data([](const std::vector<double>& v){  return boost::math::jacobi_dn(v[1], v[0]);  }, [](const std::vector<double>& v){ return v[4];  });


#if defined(TEST_GSL) && !defined(COMPILER_COMPARISON_TABLES)
   std::cout << "Screening GSL data:\n";
   screen_data([](const std::vector<double>& v)
   {  
      double s, c, d;
      gsl_sf_elljac_e(v[0], v[1] * v[1], &s, &c, &d);
      return d;
   }, [](const std::vector<double>& v){ return v[4];  });
#endif

   unsigned data_used = data.size();
   std::string function = "jacobi_dn[br](" + boost::lexical_cast<std::string>(data_used) + "/" + boost::lexical_cast<std::string>(data_total) + " tests selected)";
   std::string function_short = "jacobi_dn";

   double time;

   time = exec_timed_test([](const std::vector<double>& v){  return boost::math::jacobi_dn(v[1], v[2]);  });
   std::cout << time << std::endl;
#if !defined(COMPILER_COMPARISON_TABLES) && (defined(TEST_GSL) || defined(TEST_RMATH))
   report_execution_time(time, std::string("Library Comparison with ") + std::string(compiler_name()) + std::string(" on ") + platform_name(), function, boost_name());
#endif
   report_execution_time(time, std::string("Compiler Comparison on ") + std::string(platform_name()), function_short, compiler_name() + std::string("[br]") + boost_name());
   //
   // Boost again, but with promotion to long double turned off:
   //
#if !defined(COMPILER_COMPARISON_TABLES)
   if(sizeof(long double) != sizeof(double))
   {
      time = exec_timed_test([](const std::vector<double>& v){  return boost::math::jacobi_dn(v[1], v[0], boost::math::policies::make_policy(boost::math::policies::promote_double<false>()));  });
      std::cout << time << std::endl;
#if !defined(COMPILER_COMPARISON_TABLES) && (defined(TEST_GSL) || defined(TEST_RMATH))
      report_execution_time(time, std::string("Library Comparison with ") + std::string(compiler_name()) + std::string(" on ") + platform_name(), function, boost_name() + "[br]promote_double<false>");
#endif
      report_execution_time(time, std::string("Compiler Comparison on ") + std::string(platform_name()), function_short, compiler_name() + std::string("[br]") + boost_name() + "[br]promote_double<false>");
   }
#endif


#if defined(TEST_GSL) && !defined(COMPILER_COMPARISON_TABLES)
   time = exec_timed_test([](const std::vector<double>& v)
   {  
      double s, c, d;
      gsl_sf_elljac_e(v[0], v[1] * v[1], &s, &c, &d);
      return d;
   });
   std::cout << time << std::endl;
   report_execution_time(time, std::string("Library Comparison with ") + std::string(compiler_name()) + std::string(" on ") + platform_name(), function, "GSL " GSL_VERSION);
#endif

   return 0;
}

