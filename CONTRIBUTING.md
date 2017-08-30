# How to contribute

We are happy about contributions to AMICI in any form (new functionality, documentation, bug reports, ...).

## Making code changes

When making code changes:

* Check if you agree to release your contribution under the conditions provided in `LICENSE`
* Start a new branch from `master`
* Implement your changes
* Submit a pull request
* Make sure your code is documented appropriately
  * Run `mtoc/makeDocumentation.m` to check completeness of your documentation
* Make sure your code is compatible with C++11, `gcc` and `clang`
* when adding new functionality, please also provide test cases (see `tests/cpputest/`)
* Write meaningful commit messages
* Run all tests to ensure nothing got broken
  * Run `tests/cpputest/wrapTestModels.m` followed by CI tests `scripts/run-build.sh && scripts/run-cpputest.sh`
  * Run `examples/amiExamples.m`
* When all tests are passing and you think your code is ready to merge, request a code review