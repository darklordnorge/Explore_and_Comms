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
/*Update the network*/
void MyController::step ( const vector <double> &input, vector <double> &output){
    /*set values for the inputlayer*/
    for(int i = 0;i < input.size();i++){
        input_layer[i] = get_value(input, i);
    }

    /*Set input_layer bias*/
    input_layer[num_input] = 1.0;

    /*reset the output_layer*/
    for(int i = 0;i < num_output;i++){
        output_layer[i] = 0.0;
    }

    /*add the weights from input-to-hidden_layer*/
    for(int i = 0;i < hidden_layer_size;i++){
        for(int j = 0;j < num_input+1;j++){
            hidden_layer[i] += (input_layer[j] * (weights1[j][i]));
        }
    }

    /*calculate sigmoid for hidden_layer*/
    for(int i = 0;i < hidden_layer_size;i++){
        hidden_layer[i] = f_sigmoid(hidden_layer[i]);
    }

    /*add the bias for the output_layer*/
    hidden_layer[hidden_layer_size] = 1.0;

    /*add the weights from the hidden-to-output_layer*/
    for(int i = 0;i < num_output;i++){
        for(int j = 0;j < hidden_layer_size+1;j++){
            output_layer[i] += (hidden_layer[j] * weights2[j][i]);
        }
    }

    /*calculate the sigmoid for the output_layer*/
    for(int i = 0;i < num_output;i++){
        output[i] = f_sigmoid(output_layer[i]);
    }
}

/* -------------------------------------------------------------------------------------- */

void MyController::reset ( void ){
    // reset the state of neurons
}
/* -------------------------------------------------------------------------------------- */

void MyController::read_from_file(void) {
}
int MyController::get_num_input ( void ){
    return num_input;
}
int MyController::get_num_output ( void ){
    return num_output;
}