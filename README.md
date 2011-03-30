First Extension
===============

Instructions for creating a SWIG native extension on OS 10.6:

Download and install PCRE library (pcre-8.00-0.dmg) from Rudix.
Download and install boost-1.43 (boost-1.43.0-0.dmg) from Rudix.

 * http://rudix.org/packages-abc.html
 * http://rudix.org/packages-opq.html

As an alternative to Rudix, you could use another package manager like Homebrew, Macports or Fink.

Download SWIG from http://www.swig.org/

    tar -zxf swig*.gz  #extract swig
    cd swig*

Patch the configure script, configure and make:

    patch -p0 <./configure.patch
    ./configure
    make

If you want to make sure it works:

    make check-ruby-examples

And install:

    sudo make install

Building your extension
-----------------------

* Create your cpp and .h files.
* Create a proper .i file for SWIG. (See the SWIG documentation in the Doc folder or online)
* Create an extconf.rb for your module.

Run in order:
    $ swig -c++ -ruby modulename.i  # Generate the wrapper files
    $ ruby extconf.rb               # Generate the Makefile for the module
    $ make                          # Make the module. It will be made as modulename.bundle

Now try your extension:
    $ irb
    ruby :001> require './modulename.bundle'
     => true
    ruby :002> a = Modulename::Classname.new
     => #<Modulename::Classname:0x00000101118738>
    ruby :003> a.somemethod
     => "result"

Notes for Ruby 1.9.2 and SWIG 2.0.2
-----------------------------------

If you are passing char* string pointers around, you will get an error when you run make:

    error: ‘STR2CSTR’ was not declared in this scope

Ruby 1.9.2 has removed STR2CSTR. The solution is to replace all occurrences of STR2CSTR with StringValuePtr.
Try running this to do the replace for you:

    $ sed -i -e 's/STR2CSTR/StringValuePtr/' *.cxx

Source: [http://rubyforge.org/tracker/index.php?func=detail&aid=28565&group_id=285&atid=1167]

Other notes
-----------

If you are creating your own Makefile, use these includes when building your extension,
however note you do not need to do this if you use extconf.rb.

    RUBYINCLUDES="-I`cd $MY_RUBY_HOME/include/*/*/ruby/..;pwd` -I`cd $MY_RUBY_HOME/include/*;pwd`"
    LDFLAGS=-L$MY_RUBY_HOME/lib
    echo "-I'`cd $MY_RUBY_HOME/include/*/*/ruby/..;pwd`' -I'`cd $MY_RUBY_HOME/include/*;pwd`'"
