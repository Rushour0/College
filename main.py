import os
  
def parent_child():
    n = os.fork()
  
    # n greater than 0  means parent process
    if n > 0:
        print("Parent process and id is : ", os.getpid())
  
    # n equals to 0 means child process
    elif n == 0:
        print("Child process and id is : ", os.getpid())

if __name__ == "__main__": 
    # Driver code
    parent_child()