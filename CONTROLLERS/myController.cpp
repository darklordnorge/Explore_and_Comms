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
/*this function create the nueral network and initialized it weights to genes*/
void MyController::init ( const vector <chromosome_type> &genes ){
    vector<double> new_gene; //vector to hold the scalled genes

    /*initialize the layers*/
    input_layer.assign(num_input+1, 0.0);
    hidden_layer.assign(hidden_layer_size+1, 0.0);
    output_layer.assign(num_output, 0.0);

    new_gene.resize(genes.size());

    /*initialize input-to-hidden layer weights*/
    for(int i = 0;i < num_input+1;i++){
        for(int j = 0;j < hidden_layer_size;j++){
            weights1[i][j] = 0.0;
        }
    }

    /*initialize the hidden-to-output layer weights*/
    for(int m = 0;m < hidden_layer_size+1;m++){
        for(int n = 0;n < num_output;n++){
            weights2[m][n] = 0.0;
        }
    }

    /*scales genes from -5.0 to 5.0 */
    for(int i = 0;i < genes.size();i++){
        new_gene[i] = ((high_bound - low_bound) * get_value(genes, i)) + low_bound;
    }

    /*set the weights*/
    int counter = 0;
    for(int i = 0;i < num_input+1;i++){
        for(int j = 0;j < hidden_layer_size;j++){
            weights1[i][j] = new_gene[counter];
            counter++;
        }
    }
    for(int m = 0;m < hidden_layer_size+1;m++){
        for(int n = 0;n < num_output;n++){
            weights2[m][n] = new_gene[counter];
            counter++;
        }
    }
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
