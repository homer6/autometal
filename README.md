# Autometal

Autometal is a cluster-aware package manager for installing bare metal operators.

### What can you do with Autometal?

1. Install and manage a Kubernetes cluster on baremetal (or cloud VM), with a single command.
   1. By default, this is an HA (high availability) cluster where masters will be replaced on failure.
   
2. Install an Autometal registry. You can use autometal.io as the default autometal registry, or you can run your own.

![AutoMetal Architecture](https://raw.githubusercontent.com/homer6/autometal/master/docs/resources/autometal_architecture.jpg)


### Requirements

1. x86-64 Linux (Ubuntu 18) (please open an issue to request additional platform support)

### Installing

`curl https://get.autometal.io/install.sh | sudo bash`

### Running

```
autometal
```


### Building

```
sudo apt install cmake
cmake -Wno-dev .
make -j12
```


License
----
MIT


Links
----
https://github.com/operator-framework/awesome-operators
