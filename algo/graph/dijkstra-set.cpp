t e m p l a t e   < t y p e n a m e   T >  
 v e c t o r   < T >   d i j k s t r a ( c o n s t   g r a p h < T >   & g ,   i n t   s t a r t )   {  
     a s s e r t ( 0   < =   s t a r t   & &   s t a r t   <   g . n ) ;  
     v e c t o r < T >   d i s t ( g . n ,   n u m e r i c _ l i m i t s < T > : : m a x ( ) ) ;  
     d i s t [ s t a r t ]   =   0 ;  
     s e t <   p a i r < T ,   i n t >   >   s ;  
     s . e m p l a c e ( d i s t [ s t a r t ] ,   s t a r t ) ;  
     w h i l e   ( ! s . e m p t y ( ) )   {  
         i n t   i   =   s . b e g i n ( ) - > s e c o n d ;  
         s . e r a s e ( s . b e g i n ( ) ) ;  
         f o r   ( i n t   i d   :   g . g [ i ] )   {  
             i f   ( g . i g n o r e   ! =   n u l l p t r   & &   g . i g n o r e ( i d ) )   {  
                 c o n t i n u e ;  
             }  
             a u t o   & e   =   g . e d g e s [ i d ] ;  
             i n t   t o   =   e . f r o m   ^   e . t o   ^   i ;  
             i f   ( d i s t [ i ]   +   e . c o s t   <   d i s t [ t o ] )   {  
                 s . e r a s e ( { d i s t [ t o ] ,   t o } ) ;  
                 d i s t [ t o ]   =   d i s t [ i ]   +   e . c o s t ;  
                 s . e m p l a c e ( d i s t [ t o ] ,   t o ) ;  
             }  
         }  
     }  
     r e t u r n   d i s t ;  
     / /   r e t u r n s   n u m e r i c _ l i m i t s < T > : : m a x ( )   i f   t h e r e ' s   n o   p a t h  
 } 