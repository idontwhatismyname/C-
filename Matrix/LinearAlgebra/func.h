matrix *InitializeMatrix();
void ReleaseMatrix(matrix *mat);
matrix *ReadMatrix();
database read();
void PrintMatrix(const matrix* const mat);
void Replacement(const database row1[],database row2[],const int col,const database multiple);
void Interchange(database *row1,database *row2,const int col);
void Scaling(database *row,const database scales,const int col);