env = Environment()  # Initialize the environment
# env.VariantDir('build/','.')
env["CXX"] = "clang++"
env.Append(CCFLAGS='-std=c++11 -stdlib=libc++ -Wall ')
env.Program('main', Glob('*.cpp'))
