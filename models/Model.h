#include <vector>
#include <fstream>
#include <iostream>

#ifndef MODELS_MODEL_H_
#define MODELS_MODEL_H_

template <class T>
class Model {
	protected:
		vector<T> data;
		string filename;


		void loadData(){
			ifstream input;
			input.open(this->filename, ios_base::in);
			if(input.fail())
				cerr << "Unable to open the file" << endl;
			T * element = new T();
			while(!input.eof()){
				input >> *element;
				this->data.push_back(*element);
			}
			input.close();
		}

		void storeData(){
			ofstream output;
			output.open(this->filename, ios_base::trunc);
			if(output.fail())
			  cerr << "Unable to open the file" << endl;

			for(auto &element : data)
				output << element;

			output.close();
		}
	public:
		Model(string filename){
			this->filename = filename;
			this->loadData();
		}
};

#endif /* MODELS_MODEL_H_ */
