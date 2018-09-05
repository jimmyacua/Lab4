#define KEY 0xB50060	// Valor de la llave del recurso

   class Buzon {
     public:
      Buzon();
      ~Buzon();
      int Enviar( char * mensaje );
      int Recibir( char *mensaje, int len );   // len es el tamaño máximo que soporte la variable mensaje
     private:
      int id;		// Identificador del buzon
   };
