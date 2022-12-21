dev_base - Base class code

dev_impl - User defined class code

dev_ctx - Polymorphic context where User defined class code is used

dev_algo - Behaviour procedures for User defined classes in Polymorphic context. MISSING in current approach, because behaviour is coupled with dev_impl

dev_factory - Functions that create User defined class instances for end user.

user.cpp - main code. Depicts how end user would create containers with User defined class instances.