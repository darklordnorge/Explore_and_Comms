#include "myController.h"

MyController::MyController(){
  compute_genotype_length();
}

MyController::~MyController(){

}
/*this function compute the genotype length (i.e. no. of synoptic weights) */
void MyController::compute_genotype_length ( void ){
    genotype_length = (((num_input+1) * hidden_layer_size) +
    ((hidden_layer_size +1 ) * num_output));
}

/* -------------------------------------------------------------------------------------- */

void MyController::init ( const vector <chromosome_type> &genes ){

    //this function create the nueral network and initialized it weights to genes

}

/* -------------------------------------------------------------------------------------- */

void MyController::step ( const vector <double> &input, vector <double> &output){

    //update the network

}

/* -------------------------------------------------------------------------------------- */

void MyController::reset ( void ){

    // reset the state of neurons

}


/* -------------------------------------------------------------------------------------- */
