#include <iostream>
#include <cstring>
class myvector {
  int *p; // base pointer of the vector
  unsigned int size; // size of the vector
  bool shallow;
//flag indicating whether this is a shallow copy of another myvector
  public:
/*create an empty vector */
    myvector():p(nullptr),size(0),shallow(false){}
/* create a vector of length size initialized to 0 */
    myvector(unsigned int n):size(n),shallow(false)
    {
        p=new int[n];
        std:: fill(p,p+n,0);
    }
/*copy constructor. Can be shallow or deep depending on the option */
    myvector(myvector& v, bool shallow=true)
    {
        size=v.size;
        this->shallow=shallow;//CHANGE
        if(shallow)
        {
            p=v.p;
        }
        else
        {
            p= new int[size];
            for(unsigned int i=0;i<size;i++)
            {
                p[i]=v.p[i];
            }
        }
    }
/* return the base pointer to the vector */
    int* get_ptr() const
    {
        return p;
    }
/* return the size of the vector */
    constexpr unsigned int get_size() const
    {
        return size;
    }
/* Return the shallow flag */
    bool is_shallow() const
    {
        return shallow;
    }
/*update the element at index i with val*/
    void update(unsigned int i, int val)
    {
         if (i < size)
          p[i]=val;
    }
/*return the element at index i*/
    constexpr int get(unsigned int i) const
    {
        if (i < size)
           return p[i];
    }
/*print the vector contents in the console */
    void print() const
    {
        for (unsigned int i=0;i<size;++i)
        {
            std::cout<<p[i]<<"\t";
        }
        std::cout<<std::endl;
    }
/*Expand the vector and insert a new value at the end.*/
    void push_back(int val)
    {
        int * p1=new int[size+1];
        for (unsigned int i=0;i<size;++i)
        {
            p1[i]=p[i];
        }
        p1[size]=val;
         if (!shallow) {
            delete[] p;
        }
        p=p1;
        size=size+1;
    }
    ~myvector(){
        if (!shallow) {
            delete[] p;
        }
    }
};
int main()
{
  myvector x(7); /*create a vector of size 7 initialized all to 0 */
  for (unsigned int i=0;i<7;i++)
     x.update(i,10+5*i);
  myvector v{x}; // shallow copy
  v.update(1,100);
  v.print();
// print the contents of x and verify that x has also changed on updating v.
  x.print();
  myvector y {x,false}; // deep copy
  y.update(1,200);
  y.print();
// print the contents of x and verify that x has NOT changed on updating y.
  x.print();
// push_back 500 on y and verify
  y.push_back(500);
  y.print();
  return 0;
}
