require 'mkmf'
create_makefile('calculator')

# Create wrapper target so it's easier to make the extension.
open("Makefile", "a") do |mf|
  mf.puts <<-EOM
SWIG=swig
SWIG_I=*.i

wrapper: $(SWIG_I)
	$(SWIG) -c++ -ruby $(SWIG_I)
	sed -i '' -e 's/STR2CSTR/StringValuePtr/' *.cxx
  EOM
end
