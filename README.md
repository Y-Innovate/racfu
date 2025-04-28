![RACFu Logo](logo.png)

A standardized JSON interface for RACF that enables seemless exploitation by programming languages that have a foreign language interface for C/C++ and native JSON support.

## Description

As automation becomes more and more prevalent, the need to manage the security environment programmaticaly increases. On z/OS that means managing a security product like the IBM **Resource Access Control Facility** _(RACF)_. RACF is the primary facility for managing identity, authority, and access control for z/OS. There are more than 50 callable services with assembler interfaces that are part of the RACF API. The complete set of interfaces can be found [here](http://publibz.boulder.ibm.com/epubs/pdf/ich2d112.pdf).

While there are a number of languages that can be used to manage RACF, _(from low level lnaguages like Assembler to higher level languages like REXX)_, the need to be able to easily exploit RACF management functions using existing indurstry standard programming languages and even programming languages that don't exist yet is paramount. The RACFu project is focused on making RACF management functions available to all programming languages that have native JSON support and a foreign language interface for C/C++. This will make it easier to pivot to new tools and programming languages as technology, skills, and business needs continue to evolve in the forseeable future.

## Getting Started


## Minimum z/OS & Language Versions

All versions of **z/OS** and the **IBM Open Enterprise SDK for Python** that are fully supported by IBM are supported by RACFu.
* [z/OS Product Lifecycle](https://www.ibm.com/support/pages/lifecycle/search/?q=5655-ZOS,%205650-ZOS)
* [IBM Open Enterprise SDK for Python Product Lifecycle](https://www.ibm.com/support/pages/lifecycle/search?q=5655-PYT)

### Dependencies

* **R_SecMgtOper (IRRSMO00)**: Security Management Operations.
  * More details about the authorizations required for **IRRSMO00** can be found [here](https://www.ibm.com/docs/en/zos/latest?topic=operations-racf-authorization).
* **R_Admin (IRRSEQ00)**: RACF Administration API.
  * More details about the authorizations required for **IRRSEQ00** can be found [here](https://www.ibm.com/docs/en/zos/latest?topic=api-racf-authorization).
* **RACF Subsystem Address Space**: This is a dependency for both **IRRSMO00** and **IRRSEQ00**.
  * More information can be found [here](https://www.ibm.com/docs/en/zos/latest?topic=considerations-racf-subsystem).
* **z/OS Language Environment Runtime Support**: RACFu is compiled using the **IBM Open XL C/C++ 2.1** compiler, which is still fairly new and requires **z/OS Language Environment** service updates for runtime support.
  * More information can be found in section **5.2.2.2 Operational Requisites** on page **9** in the [Program Directory for IBM Open XL C/C++ 2.1 for z/OS](https://publibfp.dhe.ibm.com/epubs/pdf/i1357012.pdf).


### Installation

> :bulb: _Note: You can also [Download & Install RACFu from GitHub](https://github.com/ambitus/racfu/releases)_

```shell
python3 -m pip install racfu
```

## Help
* [GitHub Discussions](https://github.com/ambitus/racfu/discussions)

## Authors

* Leonard Carcaramo: lcarcaramo@ibm.com
* Elijah Swift: Elijah.Swift@ibm.com
* Frank De Gilio: degilio@us.ibm.com
* Joe Bostian: jbostian@ibm.com
