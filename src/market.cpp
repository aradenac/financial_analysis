#include "market.h"
#include "framework.h"
#include <curlpp/cURLpp.hpp>
#include <curlpp/Options.hpp>
#include <stdlib.h>
#include <string.h>
using namespace faf;

void* Realloc(void* ptr, size_t size)
{
  if(ptr)
    return realloc(ptr, size);
  else
    return malloc(size);
};

char* m_pBuffer = nullptr;
size_t buffer_size = 0;

// Callback must be declared static, otherwise it won't link...
size_t WriteMemoryCallback(char* ptr, size_t size, size_t nmemb)
{

  // Calculate the real size of the incoming buffer
  size_t realsize = size * nmemb;



  size_t m_Size = 0;
  // (Re)Allocate memory for the buffer
  m_pBuffer = (char*) Realloc(m_pBuffer, m_Size + realsize);

  // Test if Buffer is initialized correctly & copy memory
  if (m_pBuffer == NULL) {
    realsize = 0;
  }

  memcpy(&(m_pBuffer[m_Size]), ptr, realsize);
  m_Size += realsize;

    buffer_size = realsize;

  // return the real size of the buffer...
  return realsize;
};


market::market(framework* f, const string& name)
{
    m_name = name;
    m_framework =f;

    // curlpp write cb
    curlpp::types::WriteFunctionFunctor functor(WriteMemoryCallback);
    curlpp::options::WriteFunction *test = new curlpp::options::WriteFunction(functor);
    m_framework->m_curl_handle.setOpt(test);
}

void market::do_your_job(){
    cout << "doing job for market " <<m_name<<endl;
    update();
    parse();
    check_alerts();
}
void market::update(){
    // fills the static m_pBuffer
    m_framework->m_curl_handle.perform();
}
void market::parse(){

}
void market::check_alerts(){}
void market::add_indicator(const string& name, shared_ptr<indicator> indicator){}
void market::remove_indicator(const string& name){}
