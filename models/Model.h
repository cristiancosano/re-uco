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
			if(input.fail()){
				cerr << "Error: Unable to open the file " + filename + " to load data" << endl;
			}
			else{
				T * element = new T();
				while(!input.eof()){
					input >> *element;
					if(!element->isEmpty())
						this->data.push_back(*element);
					element = new T();
				}
				input.close();
				/*cout<<"Datos cargados"<<endl;
				for (auto element : data){
					cout<<element<<endl;
				}*/
			}
		}

		void storeData(){
			ofstream output;
			output.open(this->filename, ios_base::out | ios_base::trunc);
			if(output.fail())
			  cerr << "Unable to open the file" << endl;
			/*cout<<"Datos a guardar"<<endl;
			for (auto element : data){
				cout<<element<<endl;
			}*/
			for(auto element = data.begin(); element != data.end(); element++){
				output << *element;
				if(element != data.end()) output << endl;
			}

			//for(auto &element : data)
			//	output << element << endl;

			output.close();
		}
	public:
		Model(string filename){
			this->filename = filename;
			this->loadData();
		}
};

#endif /* MODELS_MODEL_H_ */
