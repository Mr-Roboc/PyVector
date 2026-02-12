#include<pybind11/pybind11.h>

#include<pybind11/stl.h>


#include<fmt/core.h>

namespace py = pybind11;


int dot_product(const std::vector<int> &v1, const std:: vector<int> &v2){
    if (v1.size()!=v2.size()){
       throw  std:: runtime_error("Vector must be of same  size!");

    }

   fmt:: print("Dot product for size \n", v1.size());
   int result = 0;
    for(int i =0;i<v1.size();i++){
     result = result + (v1[i] * v2[i]);
    }

    return result;

}

//2. The Binding

PYBIND11_MODULE(py_vector,m){
   m.doc() = "Vector math plugin using fmt";

   m.def("dot_product", &dot_product,"A function that adds two numbers");

} 
