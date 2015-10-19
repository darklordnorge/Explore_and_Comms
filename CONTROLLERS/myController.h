#ifndef _MYCONTROLLER_
#define _MYCONTROLLER_

#include "controller.h"
#include "vector"

class MyController : public Controller {

private:
    static const int hidden_layer_size = 3;
    double weights1[num_input+1][hidden_layer_size];
    double weights2[hidden_layer_size+1][num_output];
    vector<double> input_layer;
    vector<double> hidden_layer;
    vector<double> output_layer;
    const static double high_bound = 5.0;
    const static double low_bound = -5.0;
// here is you data members
public:
/* -------------------------------------------------------------------------------------------------- */
/*                                             VIRTUAL FUNCTIONS                                      */
/* -------------------------------------------------------------------------------------------------- */
   MyController();
   ~MyController();
   void init                          ( const vector <chromosome_type> &genes );
   void step                          ( const vector <double> &input_array, vector <double> &output_array);
   void reset                         ( void );
   void compute_genotype_length       ( void );
/* -------------------------------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------------------------------- */
// and any other functions you might need

};

#endif
