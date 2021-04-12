/*
 * Create a framework (that is, use the Template Method pattern) that takes a
 * list of file names on the command line. It opens each file except the last
 * for reading, and the last file it opens for writing. The framework will
 * process each input file using an undetermined policy and write the output to
 * the last file. Inherit to customize this framework to create two separate
 * applications:
 * 1) Converts all the letters in each file to uppercase.  
 * 2) Searches the files for words given in the first file
*/


class AppFramework {
  protected:
    virtual void CaseConverter() = 0;
    virtual void Searcher() = 0;
  public:
};

class UpperCaseApp :public AppFramework {
  protected:
    void CaseConverter() {

    }
};

class SearchApp : public AppFramework {
  protected:
    void Searcher() {

    }
};

