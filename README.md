# Autometal

Autometal is a cluster-aware package manager for installing bare metal operators.

### What can you do with Autometal?

1. Install and manage a Kubernetes cluster on baremetal (or cloud VM), with a single command.
a) By default, this is an HA (high availability) cluster where masters will be replaced on failure.
b) By default, this cluster will auto-upgrade to the latest version of Kubernetes with no downtime.
2. Install an Autometal registry. You may use autometal.io as the default autometal registry, or you may run your own.

### Installing

`curl https://get.autometal.io/install.sh | sudo bash`

### Running

`autometal`


License
----
MIT

