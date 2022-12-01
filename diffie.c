#include <stdio.h>
/*
 * This is a simple explanation of Diffie Hellman concept for exchanging a secret key
*/

//Of course this is just a concept, secret keys are much bigger numbers
//and are kept in secret files!
#define PRIME_AGREED_ON 13
#define GENERATOR_AGREED_ON 6
#define SECRETKEY 5
#define PUBLIC_KEY_RECIEVED 9

//This explains how a public key is created
//This key should be sent to the other side of the communication
//Note: PUBLIC_KEY_RECIEVED was calculated by the other side using same algorithm
int my_public_key(){
  // public_key = Generator to the power of privatekey MOD prime
  int result = 1;
  int prime = PRIME_AGREED_ON;
  int gen = GENERATOR_AGREED_ON;
  int priv = SECRETKEY;
  while (priv!=0) {
    result *= gen;
    priv--;
  }
  return result % prime;
}

//This exaplain what to do with recieved public keys in order
//to calculate the common secret key between the two communicators.
//If the other side uses this calculation with the public key that we created above
//They should get the same secret key that we will calculate now
int common_secret_key(){
  // common_secret_key = recieved public key to the power of privatkey MOD prime
  int pkr = PUBLIC_KEY_RECIEVED;
  int prime = PRIME_AGREED_ON;
  int gen = GENERATOR_AGREED_ON;
  int priv = SECRETKEY;
  int result = 1;

  while (priv!=0) {
    result *= pkr;
    priv--;
  }
  return result % prime;
}

int main() {
  printf("the secret is %d\n",common_secret_key());
  return 0;
}
